function ex3()
T = table({'Jumpers';'Jumpers';'Jumpers';'Trousers';'Trousers';'Trousers';'T-shirts';'T-shirts';'T-shirts';'T-shirts';'T-shirts'},{'Blue';'Brown';'Green';'Black';'Grey';'White';'Blue';'Green';'Red';'White';'Yellow'},[2;3;5;3;2;1;1;2;3;2;1],{'04/2005';'02/2013';'01/2015';'06/2012';'04/2011';'12/2013';'05/2010';'09/2014';'01/2012';'03/2008';'11/2012'},'VariableNames',{'Type','Color','Quantity','Bought'});
a=[2;3;5;3;2;1;1;2;3;2;1];[m,p]=max(a);
A=T.Type(p);
A=cell2mat(A);
A=A(1:7);

C=T.Color(p);
C=cell2mat(C);
C=C(1:5);

B=T.Bought(p);
B=cell2mat(B);
B=B(4:7);
B=str2num(B);
d=(2020*11-(2005+2013+2015+2012+2011+2013+2010+2014+2012+2008+2012))/11;
d=ceil(d);
M=strcat(A,{32},C);
M=cell2mat(M);
disp(M)
disp(d)
end
