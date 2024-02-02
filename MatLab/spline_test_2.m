clf; clc; clear;

for n = 4:110
beg = 1; 
en = 10;
x = linspace(beg, en, n);
h = x(2) - x(1);
y = sin(x);
D = y;
dif2y = y;
diffy = y;
grid on;
hold on;
for p = 1:2
    for i = n:-1:1 + p
        dif2y(i) = dif2y(i) - dif2y(i - 1);
        if (p == 1)
            diffy(i) = diffy(i) - diffy(i - 1);
        end
    end
end

diffy = diffy(1, 2:n);
dif2y = dif2y(1, 3:n) * (3 / h ^ 2);


nb = n-2;
Y = [[4, 1], zeros([1, nb - 2])];
for i = 2:nb - 1
    Y = [Y; zeros([1, i - 2]), [1, 4, 1], zeros([1, nb - (i - 2) - 3])];
end
Y = [Y; zeros([1, nb - 2]), [1, 4]];
B = [0, dif2y * Y^(-1), 0];
C = diffy / h - h/3 * (2 * B(1:n-1) + B(2:n));
A = (-B(1:n-1) + B(2:n)) / (3 * h);

dev = zeros(1,n-1);
l = 1;
mDev = -1;
% curSp = [0,0,0,0];
for i = 1:(n-1)
    Sp = [A(i), B(i), C(i), D(i)];
    xi =x(l):0.0001:x(l+1);
    curY = polyval(Sp,xi-x(l));
    y1 = sin(xi);
    for j = 1:length(curY)-1
            if abs(curY(j) - y1(j)) > dev(l)
                dev(l) = abs(curY(j) - y1(j));
                if dev(l) >mDev
                    mDev = dev(l);
                end
                
            end
    end

    j = 1;
    l = l + 1;
end
end
mDev
















plot(dev(1, 1:n-10), 'o-m')


