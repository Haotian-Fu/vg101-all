mass = input('');       %input the mass to calculate
x = input('','s');      %ask the user which conversion is needed
s2p=[0]; p2k=[0]; k2s=[0];      %make the result in matrix forms
switch x
    case 'stones to pounds'
        s2p = mass.*14;     %1 stone = 14 pounds
        disp(s2p);
    case 'pounds to kg'
        p2k = mass.*(6.35/14);      %1 stone = 14 pounds = 6.35 kg
        disp(p2k);
    case 'kg to stones'
        k2s = mass./6.35;       %1 stone = 6.35 kg
        disp(k2s);
end