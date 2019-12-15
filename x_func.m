function [x] = x_func(t)
    if t<2 
        x =  2*t; 
    end
    if t >= 2 
        x = -2*t; 
    end
end