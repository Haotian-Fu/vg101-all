difficulty = input('Select your difficulty(Easy/Hard/Customize): ','s');
[w,g,r,o,n,p] = input4wgro(difficulty);
% I think 1 unit= w

[up,dw,lf,rg] = inputcar(n);    
%the number of cars in every direction, the symbol means the direction cars come from.

axis([0 10*w 0 10*w]);
box off
% define the size of the whole figure

hold on
[carlf,carrg,carup,cardw]=carpara(lf,rg,up,dw,w,p);
[lightg,lighto,lightr] = lightpara(g,o,r);
% initialization of cars and lights
crash = 0;
counting = g+o+0.1;
status = 1;
ifgreen = 1;
win = 0;
while true
    clf
    crossroads(w);
    counting = counting-0.1;
    drawlight(lightg,lightr,lighto,status,w);
    if counting < o
        status = 2;
    end
    if counting <= 0
        ifgreen = not(ifgreen);
        counting = g+o;
        status = 1*ifgreen+3*not(ifgreen);
    end
    % light change
    for i=1:lf
        move(carlf(i),w);
        if carlf(i).position(1)==3*w && status~=1
            if carlf(i).jumpred < p
                violate(carlf(i));
            else
                carlf(i).motion = 0;
                remove(carlf(i),w);
            end
        end
        if carlf(i).motion == 0 && i<lf
            carlf(i+1).motion = 0;
            remove(carlf(i+1),w);
        elseif i<lf
            carlf(i+1).motion = 1;
        end
    end
    for i=1:rg
        move(carrg(i),w);
        if carrg(i).position(1)==6*w && status~=1
            if carrg(i).jumpred <p
                violate(carrg(i));
            else
                carrg(i).motion = 0;
                remove(carrg(i),w);
            end
        end
        if carrg(i).motion == 0 && i<rg
            carrg(i+1).motion = 0;
            remove(carrg(i+1),w);
        elseif i<rg
            carrg(i+1).motion = 1;
        end
    end
    for i=1:up
        move(carup(i),w);
        if carup(i).position(2)==6*w && status~=3
            if carup(i).jumpred <p
                violate(carup(i));
            else
                carup(i).motion = 0;
                remove(carup(i),w);
            end
        end
        if carup(i).motion == 0 && i<up
            carup(i+1).motion = 0;
            remove(carup(i+1),w);
        elseif i<up
            carup(i+1).motion = 1;
        end
    end
    for i=1:dw
        move(cardw(i),w);
        if cardw(i).position(2)==3*w && status~=3
            if cardw(i).jumpred <p
                violate(cardw(i));
            else
                cardw(i).motion = 0;
                remove(cardw(i),w);
            end
        end
        if cardw(i).motion == 0 && i<dw
            cardw(i+1).motion = 0;
            remove(cardw(i+1),w);
        elseif i<dw 
            cardw(i+1).motion = 1;
        end
    end
    %move part
    
    for i=1:lf
        draw(carlf(i)); 
        xlim([0 10*w]);
        ylim([0 10*w]);
    end    
    for i=1:rg
        draw(carrg(i)); 
        xlim([0 10*w]);
        ylim([0 10*w]);
    end    
    for i=1:up
        draw(carup(i)); 
        xlim([0 10*w]);
        ylim([0 10*w]);
    end    
    for i=1:dw
        draw(cardw(i)); 
        xlim([0 10*w]);
        ylim([0 10*w]);
    end
    %draw part

    [crash] = crash1(carlf,carrg,carup,cardw,lf,rg,up,dw);
    if crash == 1
        disp('You lose');
        break;
    else
        for i=1:lf
            if carlf(i).position(1)>10*w
                for c=1:rg
                    if carrg(c).position(1)<0
                        for q=1:up
                            if carup(q).position(2)<0
                                for a=1:dw
                                    if cardw(a).position(2)>10*w
                                        win=1;
                                    end
                                end
                            end
                        end
                    end
                end
            end
        end
    end
    if win == 1;
        disp('You win!');
        break;
    end 
    pause(0.1);
    
end

function [w,g,r,o,n,p]= input4wgro(difficulty)
switch difficulty
    case 'Easy'
        w = 10;
        g = 10;
        r = g;
        o = 5;
        n = 6;
        p = 0.1;
    case 'Hard'
        w = 10;
        g = 6;
        r = g;
        o = 1;
        n = 10;
        p = 0.5;
    case 'Customize'
        w = input('the width of the road = ');
        g = input('the time for green/red lights = ');
        r = g;
        o = input('the time for orange lights = ');
        n = input('the total number of cars = ');
        p = input('the possibility cars jump the red light');
end
end
%parameters

function crossroads(w)
p=plot([5*w,5*w],[0,4*w],'--');
p.Color = '[0.5 0.5 0.5]';
hold on
p=plot([5*w,5*w],[6*w,10*w],'--');
p.Color = '[0.5 0.5 0.5]';
p=plot([0,4*w],[5*w,5*w],'--');
p.Color = '[0.5 0.5 0.5]';
p=plot([6*w,10*w],[5*w,5*w],'--');
p.Color = '[0.5 0.5 0.5]';
%to create the dotted lines

plot([4*w,4*w],[0,4*w],'k','LineWidth',2);
plot([6*w,6*w],[0,4*w],'k','LineWidth',2);
plot([4*w,4*w],[6*w,10*w],'k','LineWidth',2);
plot([6*w,6*w],[6*w,10*w],'k','LineWidth',2);
plot([0,4*w],[4*w,4*w],'k','LineWidth',2);
plot([6*w,10*w],[4*w,4*w],'k','LineWidth',2);
plot([0,4*w],[6*w,6*w],'k','LineWidth',2);
plot([6*w,10*w],[6*w,6*w],'k','LineWidth',2);
%to create the cross roads
end
%draw the crossroads

function [up,dw,lf,rg]= inputcar(n)
while true    
    up=ceil((n/2)*rand);
    dw=ceil((n/2)*rand);
    lf=ceil((n/2)*rand);
    rg=n-up-dw-lf;
    if rg>0
        break
    else
        continue
    end
end
end
%number of cars in every direction

function [carlf,carrg,carup,cardw] = carpara(lf,rg,up,dw,w,p)
    for c = 1:lf
        carlf(c) = Car([(-2*c+1)*w,4.25*w], [w 0.5*w],p,Direction.Left,1);
        plate4(carlf(c));
        randsize(carlf(c));
        jump(carlf(c));
    end
   
    for c = 1:rg
        carrg(c) = Car([(8+2*c)*w 5.25*w], [w 0.5*w],p,Direction.Right,1);
        plate4(carrg(c));
        randsize(carrg(c));
        jump(carrg(c));
    end
    
    for c = 1:dw
        cardw(c) = Car([5.25*w -(2*c-1)*w], [0.5*w w],p,Direction.Down,1);
        plate4(cardw(c));
        randsize(cardw(c));
        jump(cardw(c));
    end
    
    for c = 1:up
        carup(c) = Car([4.25*w (8+2*c)*w], [0.5*w w],p,Direction.Up,1);
        plate4(carup(c));
        randsize(carup(c));
        jump(carup(c));
    end
end
%parameters of cars

function [lightg,lighto,lightr] = lightpara(g,o,r)
    lightg = Light(1,g);
    lighto = Light(2,o);
    lightr = Light(3,r);
end
%parameters of lights


function drawlight(lightg,lightr,lighto,status,w)
    switch status
        case 1
            draw(lightg,w);
        case 2
            draw(lighto,w);
        case 3
            draw(lightr,w);
    end

end
function [crash] = crash1(carlf,carrg,carup,cardw,lf,rg,up,dw)
    crash = 0;
    for i=1:lf
        for c=1:up
            if rectint([carlf(i).position carlf(i).size],[carup(c).position carup(c).size])>0
                crash = 1;
                break;
            end
        end
        for q=1:dw
           if rectint([carlf(i).position carlf(i).size],[cardw(q).position cardw(q).size])>0
               crash = 1;
               break;
           end
        end
    end
    
    for i=1:rg
        for c=1:up
            if rectint([carrg(i).position carrg(i).size],[carup(c).position carup(c).size])>0
                crash = 1;
                break;
            end
        end
        for q=1:dw
           if rectint([carrg(i).position carrg(i).size],[cardw(q).position cardw(q).size])>0
               crash = 1;
               break;
           end
        end
    end
end
%crash funciton