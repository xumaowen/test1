clear all;
clc;
%�Ǽ���ÿһ�������ߺ�ģ��֮��нǵ�����ֵ
sub052=importdata('affine052_genue corpus callosum Fiber Bundle_fa__Clean.txt');
%439�������ߵĴ��ţ������ʱ����Ҫ�������ߵĴ��ţ���ÿ����������ģ��ļнǵ�����ֵ
%����һ�����⣬����ÿ���㷨��ÿ����ά��������ͬ
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