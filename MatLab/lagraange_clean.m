clc;clear;clf;
time = [0,0.369,1.828];
tc = [850,1137,1175];
tcp = [850,1159,1178];
tp = [850,1180,1180];
tkl = [1221,1243,1187];
tpch = [1250,1250,1188];
tr = [1442,1295,1192];

n = length(time);
Lc = zeros([1,n]);
Lcp = zeros([1,n]);
Lp = zeros([1,n]);
Lkl = zeros([1,n]);
Lpch = zeros([1,n]);
Lr = zeros([1,n]);

for i = 1:n
    A = 1;
    for j = 1:n
        if j ~= i
            A = conv(A,[1/(time(i) - time(j)), -time(j)/(time(i) - time(j))]);
        end
    end
Lc = Lc + tc(i)*A;
end

for i = 1:n
    A = 1;
    for j = 1:n
        if j ~= i
            A = conv(A,[1/(time(i) - time(j)), -time(j)/(time(i) - time(j))]);
        end
    end
Lcp = Lcp + tcp(i)*A;
end

for i = 1:n
    A = 1;
    for j = 1:n
        if j ~= i
            A = conv(A,[1/(time(i) - time(j)), -time(j)/(time(i) - time(j))]);
        end
    end
Lp = Lp + tp(i)*A;
end

for i = 1:n
    A = 1;
    for j = 1:n
        if j ~= i
            A = conv(A,[1/(time(i) - time(j)), -time(j)/(time(i) - time(j))]);
        end
    end
Lkl = Lkl + tkl(i)*A;
end

for i = 1:n
    A = 1;
    for j = 1:n
        if j ~= i
            A = conv(A,[1/(time(i) - time(j)), -time(j)/(time(i) - time(j))]);
        end
    end
Lpch = Lpch + tpch(i)*A;
end

for i = 1:n
    A = 1;
    for j = 1:n
        if j ~= i
            A = conv(A,[1/(time(i) - time(j)), -time(j)/(time(i) - time(j))]);
        end
    end
Lr = Lr + tr(i)*A;
end

t = time(1):0.01:time(end);
gc = polyval(Lc,t);
gcp = polyval(Lcp,t);
gp = polyval(Lp,t);
gkl = polyval(Lkl,t);
gpch = polyval(Lpch,t);
gr = polyval(Lr,t);
grid on
plot(t,gc, '-b')
hold on
plot(t,gcp, '-m')
plot(t,gp, '-r')
plot(t,gkl, '-k')
plot(t,gpch, '-g')
plot(t,gr, '-k')

