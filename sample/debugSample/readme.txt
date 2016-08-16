目录格式：

异常类型
   |
   |
   |____异常名称


root
 |
 |____crash
 |      |
 |	|
 |	|____simplest-crash
 |
 |
 |____hang
 |      |
 |	|
 |	|____simplest-hang
 |
 |____.....
 |



目前先采用手动添加工程

步骤如下：

1、打开debugSample.sln
2、添加新工程，路径选择按照以上的目录格式
3、修改工程属性(all Configurations)  Configuration Properties ->  General -> Output Directory
   
   修改值为：$(SolutionDir)build\$(PlatformName)\$(ConfigurationName)

4、保存