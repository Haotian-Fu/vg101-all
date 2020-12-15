format longg
s=input('','s');        %input the function in the form of @(x)
f=str2func(s);
int=input('');          %input the interval in the form of [x1 x2]
x1=int(1);x2=int(2);x3=(x1+x2)/2;       %divide into two sub-intervals
while true
    if f(x3)*f(x1)==0
        x1=x1;
        x2=x2;
        x3=(x1+x2)/2;
        if f(x1)==0
            r=x1;
        else r=x2
            break
        end
    elseif f(x3)*f(x1)>0
        x1=x3;
        x3=(x1+x2)/2;
    elseif f(x3)*f(x1)<0
        x2=x3;
        x3=(x1+x2)/2;
    end
    if abs(x1-x3)<0.0001 && abs(x2-x3)<0.0001       %accuracy
          r=x3;        
          break
    end
end
r=round(r,3);
disp(r)
   