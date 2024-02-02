clc; clear; clf;
dyn = [];
for n = 4:110
beg = 1; 
en = 10;
x = linspace(beg, en, n);
h = x(2) - x(1);
y = TF(x);

A = [];
B = [];
grid on;
hold on;
for k = 1:n - 1
    A = [A; zeros([1, (k-1) * 3]),[h^3, h^2, h], zeros([1, (n - k) * 3])];
    A = [A; zeros([1, (k-1) * 3]),[3 * h^2,2 * h, 1], [0, 0, -1], zeros([1, (n - k - 1) * 3])];
    A = [A; zeros([1, (k-1) * 3]),[6 * h, 2, 0], [0, -2, 0], zeros([1, (n - k - 1) * 3])];
    B = [B; y(k+1) - y(k); 0; 0];
end
A = [A; [0, 2, 0], zeros(1, (n-1) * 3)];
A = [A; zeros(1, (n-1) * 3), [0, 2, 0]];
A = [A; zeros([1, (n-1) * 3]), [h^3, h^2, h]];
B = [B;0;0;y(n);];
x = inv(A) * B;

dev = 0;
amD = 1000;
mx = -1;
maxDev = -1;
mx_ind = -1;
for k = 1:n-1
    p = k - 1;
    curSp = [x(3*p + 1), x(3*p+2), x(3*p+3), y(k)];
    tmpx = linspace(0, h, amD);
    tmpy = polyval(curSp, tmpx);
    [curMx, cur_ind] = max(abs(tmpy - TF(tmpx + beg + h * (k - 1))));
    if curMx > mx
       mx = curMx;
       mx_ind = tmpx(cur_ind) + beg + h * (k - 1);
       if mx > maxDev
            maxDev = mx;
        end
    end
end
dyn = [dyn, mx];
end
maxDev
plot(dyn);
function f = TF(x)
    f = sin(x);
end


