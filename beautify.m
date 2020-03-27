function [var] = beautify(var, t, var0)
    if mod(t, T_b) ~= 0
        var = var0;
    end
end