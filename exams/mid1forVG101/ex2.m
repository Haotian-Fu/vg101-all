n= input('plate number');
plate = randperm(n);
i=1;
cnt=1;
[platenew]=move(plate(i),i,cnt);
disp(platenew);
function [platenew]=move(plate(i);i,cnt)
if plate(i)<=cnt
    platenew(i)=plate(i);
else
    move(plate(i+1),i,cnt+1);
end
end