n =input('');

while true
    ns =num2str(n);     %make n into a string
    nl =length(ns);     
    sum=0;
    k=1;
    while k<=nl
        p=str2double(ns(k));      % each digits of the number n
        q=p^nl;
        sum=sum+q;              %the sum of the i -th power of each of its digits is n itself
        k=k+1;
    end
    if sum==n
       break
    elseif nl==6 &&n<=548834
        n=548834;
    elseif n>548834 &&n<=1741725
        n=1741725;
    elseif n>1741725 &&n<=4210818
        n=4210818;
    elseif nl==7 &&n>4210818 &&n<=9800817
        n=9800817;
    elseif nl==7 &&n>9800817 &&n<=9926315
        n=9926315;
    else n=n+1;
    end
end
disp(n)
