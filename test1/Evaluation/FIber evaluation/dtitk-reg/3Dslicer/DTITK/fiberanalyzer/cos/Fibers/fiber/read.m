clear all;
clc;
sub052=importdata('012_r-cst_fa__Clean.txt');
template=importdata('dtitk_r-cst_fa__Clean.txt');
 sub052_tensor=sub052(335:1074,:);
 template_tensor=template(335:1074,:);
m=1074-335+1;
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
 
 
 
 %[m,n]=find(isnan(fiber_acos))
 %avefiber_acos=sum(fiber_acos)/len