% for exercise 1
[size,n]=initial();
hold on
[x1,y1,cint,yint]=drawinitial(size);
pause(1);
while true
    clf
    hold on
    xlim([-size 2*size]); 
    ylim([-size 2*size]); 
    rectangle('Position',[0 0 size size]);
    [bouncex,bouncey]=test(x1,y1,size);
    [x2,y2]=draw(x1,y1);
    x1=x2;
    y1=y2;
    
    %stop code
    if n==(bouncex+bouncey)
        break;
    end
    pause(1);
end



function [size,n]=initial()
size= input('size of square=');
n= input('bouncing times=');
end

function [x1,y1,cint,yint]=drawinitial(size)
xlim([-size 2*size]); 
ylim([-size 2*size]); 
rectangle('Position',[0 0 size size]);
cint = 0.5*size;
yint = cint;
plot(cint,yint,'or');
x1=cint;
y1=yint;
end

function [bouncex,bouncey]=test(x1,y1,size)
if x1==0 ||size
    bouncex=1;
end
if y1==0||size
    bouncey=1;
end
end

function [x2,y2]=draw(x1,y1)
delx=1;
dely=rand*delx;
x2= x1+delx;
y2= y1+dely;
plot(x2,y2,'or');
end
