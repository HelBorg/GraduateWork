function [Q, R] = qr_pos(A)
    
    dimOde = size(A, 1);
    [Q, R] = qr(A);
    for kCoord = 1 : dimOde
        if R(kCoord, kCoord) == 0
            error('Matrix is singular!');
        end
        if R(kCoord, kCoord) < 0
            R(kCoord, :) = -1 * R(kCoord, :);
            Q(:, kCoord) = -1 * Q(:, kCoord);
        end
    end
end

