a=input('');
d=a(1); m=a(2)-2; yc=num2str(a(3));       %give corresponding digits to variables
c=str2double(yc(1:2));y=str2double(yc(3:4));        %make eg.2012 be seperated in 20 and 12
switch m
    case 0
        m=12;y=y-1;
    case -1
        m=11;y=y-1;
end
d2=d + floor((13*m-1)/5) + y + floor(y/4) + floor(c/4) -2*c;     %formula
day=1 + mod(d2,7);

switch day
    case 1
        disp('Sunday');
    case 2
        disp('Monday');    
    case 3
        disp('Tuesday');
    case 4
        disp('Wednesday');   
    case 5
        disp('Thursday');
    case 6
        disp('Friday');   
    case 7
        disp('Saturday');
end