##### 2017年9月21日 数据处理之Pandas in Python27

##### pandas的数据结构：Series，DataFrame，索引对象

##### pandas空值表示（None，np.NaN，np.NaT，pd.NaT）一些区别：

$NaN$对于浮点数，整数，布尔值和一般对象的缺省值

$NaT$ 对于`Datetime64[ns]`的缺省值

※注：缺省值的判断请使用$np.isnan()$而非`x == np.NaN`

### Series 序列

构造：1. 通过字典构造 `sdata = {'1': 1, '2': 2} obj = pd.Series(sdata) `

此时如果要传入`index=`必须是传入的等于原来字典的序列`index = ['1', '2']`,否则数据缺省

2. 通过传入数组 `obj = pd.Series([1,2,3,4], index=['1','2','3','4'])`

使用`dict(obj)`可将Series转换成字典，可使用`pd.isnull(obj)`或`pd.notnull(obj)`来检测数据丢失

### Series 对象操作

1. 取值通过向索引中传入值或列表 `obj[ ['1', '2'] ]  `or ` obj['1']`
2. 按值要求取值 `obj[obj > 3]` 
3. 算术运算 `np.exp(obj)`, `obj * 2` ；不同Series算数自动对齐运算，索引不匹配填充NaN
4. `obj.index` `obj.value` `obj.name` 
5. 索引更改` obj.index = ['0', '1',]`
6. 值替换：`obj = obj.replace(2,222)` 值2的全部改为222，临时操作，需要复制过去 也可以传入字典修改` obj = obj.replace({1: 111,2: 222})`

### DataFrame数据结构

表示一个电子表格(二维ndarray)

1. ### 构造：

   - 传入字典或Numpy数组

   ```python
   sdata = {'state': ['Ohio','Ohio','Nevada','Nevada'],
           'year': [2000,2001,2002,2003],
           'pop': [1.5, 1.7, 2.1, 2.4]}
   frame = DataFrame(sdata)
   frame = DataFrame(sdata, columns=['year','state','pop'])
   # 默认列索引可以传入columns=[]特定顺序 有索引无法对应的则缺省为NaN
   Out []:
      year   state  pop
   0  2001    Ohio  1.5
   1  2002    Ohio  1.7
   2  2003  Nevada  2.1
   3  2004  Nevada  2.4
   ```

   - 通过`data_range` 构建日期索引在创建行索引为日期的表格

   ```python
   In [109]: Dates = pd.date_range('20170921',periods=6)
   In [110]: Dates
   Out[110]:
   DatetimeIndex(['2017-09-21', '2017-09-22',
                    '2017-09-23', '2017-09-24',
                    '2017-09-25', '2017-09-26'],
                   dtype='datetime64[ns]', freq='D')
   In [111]: df = pd.DataFrame(np.random.randn(6,4),index=Dates,columns=list('ABCD'))

   In [112]: df
   Out[112]:
                      A         B         C         D
   2017-09-21  0.606246  1.231601 -2.013539  1.129853
   2017-09-22  0.058033 -2.486042 -0.618437 -0.956751
   2017-09-23  1.790751 -1.940371  1.153815 -0.965959
   2017-09-24  0.064126 -0.424741  0.402239  1.328396
   2017-09-25  1.438693  0.508082 -0.841660 -1.180235
   2017-09-26  1.753172 -1.928433  0.142073 -0.785080
   ```

   - 传入嵌套字典的字典

   ```python
   In [116]: pop = {'Nevada':{2001:2.1, 2002:2.4}, 'Ohio':{2000:1.8, 2001:2.0,2002:2.2}}
     
   In [117]: frame_pop = pd.DataFrame(pop)
   # #此处为默认使用字典内的索引，手动指定索引：
   In [120]: frame_pop = pd.DataFrame(pop, index=[2016,2017,2018])
     
   In [121]: frame_pop
   Out[121]:
         Nevada  Ohio
   2016     NaN   NaN
   2017     NaN   NaN
   2018     NaN   NaN
   # #索引皆不存在缺省为NaN

   In [118]: frame_pop
   Out[118]:
         Nevada  Ohio
   2000     NaN   1.8
   2001     2.1   2.0
   2002     2.4   2.2
   ```

   - 传入Series对象创建

     `pd.DataFrame([Series1,Series2,Series3], index=['name1','name2','name3'])`

2. ### 操作

   - 转置

   ```python
   In [119]: frame_pop.T
   Out[119]:
           2000  2001  2002
   Nevada   NaN   2.1   2.4
   Ohio     1.8   2.0   2.2
   ```

   - 查看&选择数据

     `frame_pop.head()`不指定默认查看前5行

     `frame_pop.tail(2)`显示后三行

     `frame_pop.index`  显示行索引

     `frame_pop.colimns` 显示列索引

     `frame_pop.values` 显示数据域ndarray

     `fram_pop.describe()`快速统计汇总

     `frame_pop['Nevada']` 查看轴信息

     `frame_pop[a:b]` 查看$[a,b)$行信息

     `frame_pop[frame_pop.Nevada > 2.2]` 筛选行数据

     `frame_pop[(frame_pop.Nevada>2.0)&(frame_pop.Ohio<2.03)] `使用&或者|筛选行数据

     * 通过`loc`标签选择展示数据

     ​

     ​

     ​

     ​

   - 排序

     对轴的索引进行排序

     ```py
     In [150]: frame_pop.sort_index(axis=1,ascending=False)
     Out[150]:
           Ohio  Nevada
     2000   1.8     NaN
     2001   2.0     2.1
     2002   2.2     2.4
     ```

     对DateFrame中的值排序, NaN排在最后

     ```pyth
     In [161]: frame_pop.sort_values('Ohio') # 指定轴
     Out[161]:
           Nevada  Ohio
     2000     NaN   1.8
     2001     2.1   2.0
     2002     2.4   2.2
     ```

     - 遍历与迭代

     ​

     ​

     ​

     ​





