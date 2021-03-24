clear all;
clc;
%是计算每一个受试者和模板之间夹角的余弦值
sub052=importdata('affine052_genue corpus callosum Fiber Bundle_fa__Clean.txt');
%439是受试者的代号，计算的时候，需要换受试者的代号，求每个受试者与模板的夹角的余弦值
%这是一类问题，对于每种算法和每类纤维束都是相同
template=importdata('template_genue corpus callosum Fiber Bundle_fa__Clean.txt');
 sub052_tensor=sub052(7977:25654,:);
 template_tensor=template(7977:25654,:);
m=25654-7977+1;
% data=zeros(len,4);
% for i=1:len;
%     for j=1:4;
%          data(i,j)=str2double(tensor{i,j});
%     end
% end
% len=length(dtitk052_tensor);
sub=reshape(sub052_tensor,m*3,3);
tem=reshape(template_tensor,m*3,3);
 len=length(tem);
for i=1:len
    subject_norm(i)=norm(sub(i),2);
end
for j=1:len
    template_norm(j)=norm(tem(j),2);
end
for k=1:len
    dd(k)=dot(sub(k),tem(k));
end
 fiber_acos=dd./abs(template_norm.*subject_norm);
 avefiber_acos=sum(fiber_acos)/len
 D = abs(sub-tem).^2;
 MSE = sum(D(:))/numel(tem);