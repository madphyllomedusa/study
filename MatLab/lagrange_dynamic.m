clc;clf;
clear;

x = 0:0.1:5;
n = length(x);
y = sin(x);
lag = Lagrange(x,y,n);
dev = zeros(1,n);
for i = 1:n    
    dev(i) = abs(polyval(lag,x(i)-y(i)));
end
plot(x,dev,'o-m');

mx = -1;
ind = 0;
L = Lagrange(x,y,n);
for i = min(x):(max(x)-min(x))/1000:max(x)
    if abs(polyval(L,i) - sin(i)) > mx
        mx = abs(polyval(L,i) - sin(i));
        ind = i;
    end
end
disp('Максимальное отклонение')
mx
disp('В точке')
ind
function L = Lagrange(x,y,n)
    L = zeros([1,n]);
    for i = 1:n
        A = 1;
        for j = 1:n
            if j ~= i
                A = conv(A,[1/(x(i) - x(j)), -x(j)/(x(i) - x(j))]);
            end
        end
    L = L + y(i)*A;
    end
end