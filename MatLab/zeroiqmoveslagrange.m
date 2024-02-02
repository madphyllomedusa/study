function A = f(x, y)
 
    sz = size(x);
    A = zeros([sz(1), sz(2) + 1]);
    sz = sz(2);
 
    for k = 1:1:sz
        f = [0, 1];
        for i = 1:1:sz
            if i ~= k
                f = conv(f, [1/(x(k) - x(i)), -x(i)/(x(k) - x(i))]);
            end
        end
        tmp = size(f);
        tmp = tmp(2);
 
        if sz - tmp > 0
            f = cat(2, zeros([1, sz - tmp]), f);
        end
        [A; f]
        A = A + f * y(k);
 
    end
 
 
end
