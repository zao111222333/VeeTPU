N=256;
a=2;
b=2;
n=1:N;
AdderLogicLevel=a+b+ceil(log(n)/log(2));
MultiLogicLevel=a+b;
AdderLogicLevel(1)=0;
M=MultiLogicLevel*ones(1,N);

csvwrite('testdata.csv', [n;M;AdderLogicLevel;AdderLogicLevel+MultiLogicLevel;2*M;3*M;4*M]);