clear all;
clc;
sub052=importdata('079_sple_fa__Clean.txt');
template=importdata('atlas_sple_fa__Clean.txt');
 sub052_tensor=sub052(2537:8176,:);
 template_tensor=template(2537:8176,:);
 %-------��ȡ���ݴ�С��1������ʼ------------------------
 
 
m=8176-2537+1;   %-----------------�ܵ�������ȥС��1��ʼ��������
% data=zeros(len,4);
% for i=1:len;
%     for j=1:4;
%          data(i,j)=str2double(tensor{i,j});
%     end
% end
% len=length(dtitk052_tensor);

sub=reshape(sub052_tensor,m*3,3);
tem=reshape(template_tensor,m*3,3);%------------�޸��к���
 len=length(tem);
for i=1:len
    subject_norm(i)=norm(sub(i),2);
end
for j=1:len
    template_norm(j)=norm(tem(j),2);
end                                %--------------�����������Ķ�����
for k=1:len
    dd(k)=dot(sub(k),tem(k));
end
 fiber_acos=dd./abs(template_norm.*subject_norm);
 avefiber_acos=sum(fiber_acos)/len
 
 
 
 %[m,n]=find(isnan(fiber_acos))
 %avefiber_acos=sum(fiber_acos)/len