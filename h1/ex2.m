x=[3;2;6;8];    
y=[4;1;3;5];
disp(x);
disp(y);        %question1
y=[4;1;3;5;sum(x)];     %"the end of y" = the sum of the element x
% the definition of "the end of y" is unclear
disp(x);
disp(y);        %question2
x=[3;2;6;8];     
y=[4;1;3;5];
disp(x.^y);
disp(y);        %question3
x=[3;2;6;8];     
y=[4;1;3;5];
disp(y./x);
disp(x);        %question4
x=[3;2;6;8];    
y=[4;1;3;5];
z=x.*y;
disp(x);
disp(y);
disp(z);        %question5
x=[3;2;6;8];    
y=[4;1;3;5];
w=sum(z);       %question6
disp(z);
disp(w);
disp(x);
disp(y);
disp(w);
disp(x'*y-w);       %question7


