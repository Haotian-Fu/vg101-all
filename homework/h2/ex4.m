format longg;
r=interative();
disp(r);


function r=interative()
f =input('','s');       %function
f =str2func(f);
in =input('');      %interval
prec =input('');        %precision
x0 =in(1); x1 =in(2);
r =x0-f(x0)*(x0-x1) / (f(x0)-f(x1));
n=1;
while (abs(x0-x1)>10^(-prec)) && n<=10^prec
    x1=x0;
    x0=r;
    r =x0-f(x0)*(x0-x1) / (f(x0)-f(x1));
    n=n+1;
end

r =round(r*10^prec)/10^prec;
end

function r=recursive()
f =input('','s');       %function
f =str2func(f);
in =input('');      %interval
prec =input('');        %precision
x0 =in(1); x1 =in(2);
r =x0-f(x0)*(x0-x1) / (f(x0)-f(x1));
n=1;
if (abs(x0-x1)>10^(-prec)) && n<=10^prec
    x1=x0;
    x0=r;
    r =x0-f(x0)*(x0-x1) / (f(x0)-f(x1));
else n=n+1;
end
r =round(r*10^prec)/10^prec;
end
