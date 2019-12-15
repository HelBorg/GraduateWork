global T b;
T = 2
b = [0 1 1]
figure
fplot(@(x) x_func(x), [2,4])

function [x_transm] = DCSK(t)
    global b T;
    T = 2;
    b = [0 1 1];
    b_k = b(ceil(t/(2*T)));
    if (mod(t, 2*T) <= T)
        x_transm = x_func(t);
    elseif b_k == 0
        x_transm = - x_func(t - T);
    elseif b_k == 1
        x_transm = x_func(t - T);
    else
        throw(MException('MyComponent:noSuchVariable','Cannot get x_transm value'));
    end
end


