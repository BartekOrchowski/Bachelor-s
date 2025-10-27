%clear the workspace
clear all
close all
clc
%the parameters of simulation
ts=0.0001;
sim_time=2;
%the parameters of the object
Te=0.001;
Tm=0.2;
%the parameters of smc
k_smc=100;
M=-2;
%start of simulation
out = sim('sim_fsmc');

% Extract data (assuming uniform time base; squeeze if needed for dimensions)
t = out.tout;  % Or out.t.Time if you prefer the timeseries time
w = squeeze(out.w.Data);
w_ref = squeeze(out.w_ref.Data);
de = squeeze(out.de.Data);
e = squeeze(out.e.Data);

%results
figure(1)
plot(t,w);
grid;
hold;
plot(t,w_ref);
legend('\omega','\omega_r_e_f');
xlabel('t[s]');
ylabel('\omega [p.u.]')
figure(2)
plot(e,de);
grid;
xlabel('e');
ylabel('de')
