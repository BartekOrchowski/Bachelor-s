%% Wyczyść środowisko MATLAB
clear all;        % usuń wszystkie zmienne z przestrzeni roboczej
close all;        % zamknij wszystkie otwarte okna wykresów
clc;              % wyczyść okno poleceń

%% Parametry symulacji
ts = 0.0001;     % krok czasowy symulacji [s]
sim_time = 2;    % całkowity czas trwania symulacji [s]

%% Parametry modelu obiektu (np. silnika DC)
Te = 0.001;      % stała czasowa części elektrycznej obiektu
Tm = 0.2;        % stała czasowa części mechanicznej obiektu

%% Parametry regulatora SMC (Sliding Mode Control)
k_smc = 100;     % współczynnik wzmocnienia regulatora SMC
M = 2;           % współczynnik sterowania (określa kierunek i intensywność działania)

%% Uruchomienie symulacji modelu Simulink
% Model musi być zapisany w pliku 'sim_fsmc.slx'
out = sim('sim_fsmc');

%% Pobranie danych z wyników symulacji
t = out.tout;             % wektor czasu
w = squeeze(out.w.Data);  % prędkość rzeczywista obiektu
w_ref = squeeze(out.w_ref.Data); % prędkość zadana (wartość odniesienia)
de = squeeze(out.de.Data); % pochodna błędu (de/dt)
e = squeeze(out.e.Data);   % błąd regulacji: e = w_ref - w

%% Wizualizacja wyników

% Wykres prędkości rzeczywistej i zadanej 
figure(1)
plot(t, w);           % wykres prędkości rzeczywistej
grid on;
hold on;
plot(t, w_ref);       % wykres prędkości zadanej
legend('\omega', '\omega_{ref}');
xlabel('t [s]');
ylabel('\omega [p.u.]');
title('Prędkość rzeczywista i zadana');

% Portret fazowy (błąd e względem pochodnej de) 
figure(2)
plot(e, de);
grid on;
xlabel('e');
ylabel('de');
title('Portret fazowy (e vs de)');
hold on;
