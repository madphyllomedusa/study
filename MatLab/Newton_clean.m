clc;clf;
clear;

x = 0:0.5:5;
y = sin(x);
y_true = y;
n = length(y);

%вычисление конечных разностей
for i = 2:n
for j = n:-1:i
temp = y(j) - y(j-1);
y(j) = temp;
end
end
y;


h = x(2) - x(1);

proizv_arr = zeros([1,n]);
proizv_arr(1) = 1;

A = 1;

N = zeros([1,n]);
RN = N + y(1);
N = N +[zeros(1,length(N)- 1), y(1)];
for i = 2:n
A = 1;
for j = 2:i
A = conv(A,[1,-x(j-1)]);
end

N = N +[zeros(1,length(N)-length(A)), y(i)*A/(factorial(i-1)*(h.^(i-1)))];
end

disp('Коэффициенты многочлена Ньютона');
N
t = x(1):0.01:x(end);

g = polyval(N,t);

plot(t,g, '-b')
hold on
plot(t,sin(t),'--m')
plot(x,y_true,'ok')