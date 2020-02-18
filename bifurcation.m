function [mat] = bifurcation(fun,x0,a0,a1,N,L,p_siz)
    if ~exist('p_siz','var')
        p_siz = 1;
    end
    % initialization
    mat = zeros(N,L);
    a = linspace(a0,a1,N);
    % main loop
    format long
    for i = 1:N
        ca = a(i); % pick one parameter value at each time
        for j = 1:L % generate a sequence with length L
            if j == 1 
                pre = x0; % assign initial value
                for k = 1:500 % throw out bad data
                   nxt = fun(pre,ca); 
                   pre = nxt;
                end
            end
            nxt = fun(pre,ca); % generate sequence
            mat(i,j) = nxt; % store in mat
            pre = nxt; % use latest value as the initial value for the next round
        end
    end
    % plot 
    dcolor = [0,0,1]; % Marker color setting: blue        
    [r,c] = meshgrid(1:L,a); % associated cooridate data 
    surf(r,c,mat,'Marker','*','MarkerSize',p_siz,'FaceColor','None','MarkerEdgeColor', dcolor,'EdgeColor','None')
    view([90,0,0]) % change camera direction
    ylim([a0,a1]) % fit to data
end