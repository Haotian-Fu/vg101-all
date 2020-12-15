x=input('');
while true
    if isprime(x+1)==1 && mod(x+1,4)==1
        p=x+1;break
    else
        x=x+1;
    end
end
a=0;b=0;
[p,a,b]=findab(p,a,b);  %find a and b
disp([num2str(p),' = ',num2str(a),'^2 + ',num2str(b),'^2']);

function [p,a,b]=findab(p,a,b)
while p>a^2 + b^2
      a=a+1;
      while p>a^2+b^2       %b is inside a to make a<=b
         b=b+1;         %increase a and b to reach p==a^2+b^2
      end      
      if p==a^2+b^2
          break
      else
          b=0;          %reset b and continue the while sentences
          
      end
end
end
