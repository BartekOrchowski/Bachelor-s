%% clear the workspace
clear; close all; clc;

%% parameters of simulation
ts = 1e-4;           % krok czasowy (zgodny z fixed-step)
sim_time = 2;        % czas symulacji [s]

%% parameters of the object (model silnika DC)
Te = 0.001;          % stała elektryczna
Tm = 0.2;            % stała mechaniczna

%% parameters of super-twisting SMC
%%lambda = 2;          % współczynnik lambda w s = e + lambda*de
up_lim = 10;         % górne ograniczenie sterowania
dn_lim = -up_lim;    % dolne ograniczenie sterowania

%% start of simulation
out = sim('sim_st_smc', 'StopTime', num2str(sim_time));

%% extract data
t = out.tout;
w = squeeze(out.w.Data);          % prędkość rzeczywista
w_ref = squeeze(out.w_ref.Data);  % prędkość zadana
e = squeeze(out.e.Data);          % błąd e = w_ref - w
de = squeeze(out.de.Data);        % pochodna błędu
u= squeeze(out.u.Data);        % pochodna błędu

%% plots
figure(1);
plot(t, w, 'LineWidth', 1.3); hold on;
plot(t, w_ref, 'LineWidth', 1.3);
grid on;
xlabel('t [s]'); ylabel('\omega [p.u.]');
legend('\omega', '\omega_{ref}');
title('Prędkość rzeczywista i zadana');

figure(2);
plot(e, de, 'LineWidth', 1.3);
grid on;
xlabel('e'); ylabel('de');
title('Portret fazowy (e vs de)');

figure(3); 
plot(t, u); 
title('u - sterowanie ');