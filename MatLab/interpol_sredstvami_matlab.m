x=[1;1.5;2;2.5;3];
y=[4;-3;2;7;5];

P = polyfit(x,y,4)

t = x(1):0.01:x(end);

g = polyval(P,t);

plot(t,g, '-k')   