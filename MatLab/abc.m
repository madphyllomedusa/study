clf; clc; clear;
x = [0:1:100];
n = length(x);
beg = x(1);
en = x(n);
h = x(2) - x(1);
y = sin(x);
arD = y;
d2y = y;
dy = y;
grid on;
hold on;
for p = 1:2
for i = n:-1:1 + p
d2y(i) = d2y(i) - d2y(i - 1);
if (p == 1)
dy(i) = dy(i) - dy(i - 1);
end
end
end

dy = dy(1, 2:n);
d2y = d2y(1, 3:n) * (3 / h ^ 2);

nb = n-2;
Y = [[4, 1], zeros([1, nb - 2])];
for i = 2:nb - 1
Y = [Y; zeros([1, i - 2]), [1, 4, 1], zeros([1, nb - (i - 2) - 3])];
end
Y = [Y; zeros([1, nb - 2]), [1, 4]];
arB = [0, d2y * Y^(-1), 0];
arC = dy / h - h/3 * (2 * arB(1:n-1) + arB(2:n));
arA = (-arB(1:n-1) + arB(2:n)) / (3 * h);

dev = zeros(1,n-1);
l = 1;

for i = 1:(n-1)
curSp = [arA(i), arB(i), arC(i), arD(i)];

xi =x(l):0.01:x(l+1);
y_cur = polyval(curSp,xi-x(l));
y1 = sin(xi);
for j = 1:length(y_cur)-1
if abs(y_cur(j) - y1(j)) > dev(l)
dev(l) = abs(y_cur(j) - y1(j));
x1(l) = x(l);
end
end

j = 1;
l = l + 1;
end
plot(x1, dev, 'o-b')