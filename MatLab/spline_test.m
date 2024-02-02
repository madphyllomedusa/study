
clf; clc; clear;
x = [0,0.369,1.828];
y = [850,1137,1175];
n = length(x);
beg = x(1);
en = x(n);
h = x(2) - x(1);

D = y;
dif2y = y;
dify = y;
grid on;
hold on;

for p = 1:2
    for i = n:-1:1 + p
        dif2y(i) = dif2y(i) - dif2y(i - 1);
        if (p == 1)
            dify(i) = dify(i) - dify(i - 1);
        end
    end
end

dify = dify(1, 2:n);
dif2y = dif2y(1, 3:n) * (3 / h ^ 2);


nb = n-2;
Y = [[4, 1], zeros([1, nb - 2])];
for i = 2:nb - 1
    Y = [Y; zeros([1, i - 2]), [1, 4, 1], zeros([1, nb - (i - 2) - 3])];
end
Y = [Y; zeros([1, nb - 2]), [1, 4]];
B = [0, dif2y * Y^(-1), 0];
C = dify / h - h/3 * (2 * B(1:n-1) + B(2:n));
A = (-B(1:n-1) + B(2:n)) / (3 * h);

x1 = 0:0.1:10;
y1 = sin(x1);
plot(x,y,'ok')
% plot(x1, y1, '--k');
l = 1;
for i = 1:(n-1)
    Sp = [A(i), B(i), C(i), D(i)]
    xi =0:0.1:h;
    y_cur = polyval(Sp,xi);
    
    q = plot(xi-h,y_cur,'-r');
    input('');
    delete(q);
   
    xi = x(l):0.1:x(l+1);
    y_cur = polyval(Sp,xi-x(l));
    plot(xi,y_cur,'-r', LineWidth=1);
    
    l = l + 1;
end