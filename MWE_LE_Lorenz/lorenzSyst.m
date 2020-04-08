function dxdt = lorenzSyst(t, x, r, sigma, b)

% Parameters : r, sigma, b

% Output vector that represents combined system :
dxdt = zeros(12,1);

% Right-hand side of the Lorenz system :
dxdt(1) = -sigma*x(1) + sigma*x(2);
dxdt(2) = r*x(1) - x(1)*x(3) - x(2);
dxdt(3) = x(1)*x(2) - b*x(3);

% Variational matrix :
dxdt(4:12) = [-sigma, sigma, 0;
               r-x(3), -1, -x(1); 
               x(2), x(1), -b] ...
                        * [x(4), x(7), x(10); 
                           x(5), x(8), x(11); 
                           x(6), x(9), x(12)];

end

