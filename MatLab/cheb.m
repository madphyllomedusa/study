clc;clf;
clear;
n = 40; % n-ый многочлен Чебышёва

Tn_2 = [0,1];
Tn_1 = [1,0];
Tn_1_x2 = 0;
Tn = [0,0];
for i = 1:n-1
Tn_1_x2 = conv(Tn_1,[2,0]);
if i > 1
Tn_2= conv(Tn_2,[0,1]);
end
Tn_2 = conv(Tn_2,[0,1]);
Tn = Tn_1_x2 - Tn_2;
Tn_2 = Tn_1;
Tn_1 = Tn;
end
Tn;

T_norm = 1/(2^(n-1))*Tn;
t = -1:0.01:1;
g = polyval(Tn,t);
z = polyval(T_norm,t);
%plot(t,g, '-b')
grid on
hold on
plot(t,z, '-r')