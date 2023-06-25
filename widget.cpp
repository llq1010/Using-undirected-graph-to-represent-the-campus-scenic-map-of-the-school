#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("南工小地图");
    //初始化图
    init(g);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton0_clicked()
{
    ui->label_text->setText("我是校门，南京工业大学的校门历史可以追溯到1952年南京化工学院成立时，当时的校门是简单的铁门和砖墙，没有任何装饰。随着南京化工学院的发展壮大，校门也逐渐进行了改造和扩建。在1995年，南京化工学院更名为南京工业大学，为了配合学校的新名称，校门也进行了重新设计。新的南工大校门采用了现代化的设计理念，整体呈现出简洁、大气、典雅的风格，成为南京工业大学的标志性建筑之一。南工大校门的正中央是一座巨大的钟楼，两侧是高大的石柱，整个校门建筑气势磅礴，非常壮观。");
}

void Widget::on_pushButton1_clicked()
{
    ui->label_text->setText("我是厚学楼，南京工业大学的厚学楼是学校的标志性建筑之一，位于学校的中心位置，是学校的行政、教学和科研中心。厚学楼始建于1952年，当时是南京化工学院的第一座教学楼，后来随着学校的发展，进行了多次改扩建。现在的厚学楼由东、中、西三幢楼组成，总建筑面积达到了5.5万平方米。厚学楼内设有多个教学和行政部门，包括校长办公室、教务处、学生处、研究生院、图书馆、实验室等。在厚学楼内还有多个大型的教室和讲堂，可以容纳数百人同时上课。厚学楼是南京工业大学的重要象征之一，也是学校师生学习、教学和科研的重要场所。");
}

void Widget::on_pushButton2_clicked()
{
    ui->label_text->setText("我是体院馆，南京工业大学体育馆是学校的重要场馆之一，位于学校东区，建筑面积达到了1.6万平方米。体育馆内设有多个运动场地，包括羽毛球场、乒乓球场、篮球场、排球场、健身房等，可以满足学生和教职工的多种运动需求。体育馆还设有多个观众席，可以容纳上千人观看比赛。南京工业大学体育馆是学校各类体育比赛和活动的主要场所，也是学校体育文化交流和展示的重要平台。近年来，南京工业大学体育馆还多次承办了全国性的体育比赛和文艺演出，为学校增添了不少荣誉和光彩。");
}

void Widget::on_pushButton3_clicked()
{
    ui->label_text->setText("我是浦江操场，南京工业大学浦江操场是学校的主要体育场地之一，位于学校南区，占地面积达到了3.5万平方米。操场内设有多条田径跑道、足球场、篮球场、排球场、网球场等，可以满足师生的多种运动需求。此外，操场还设有多个观众席，可以容纳上千人观看比赛。南京工业大学浦江操场还是南京市的重要比赛场地，多次承办了全国和省市级的体育比赛和文艺演出。操场周围还有多个健身区和运动场地，供师生进行健身和休闲活动。南京工业大学浦江操场是学校体育文化建设和体育竞技的重要场所，也是师生进行体育锻炼和展示个人才艺的重要平台。");
}

void Widget::on_pushButton4_clicked()
{
    ui->label_text->setText("我是大礼堂，南京工业大学博雅堂是学校的一座重要建筑，位于学校西区，占地面积约为2.6万平方米。博雅堂是学校的文化中心，内设有多个演播厅、报告厅、会议室等多个功能区域，可以承办各种大型会议、学术报告、文艺演出等活动。此外，博雅堂还设有图书馆和阅览室，收藏了大量的书籍和资料，为师生提供了良好的学习和阅读环境。南京工业大学博雅堂是学校文化建设和学术交流的重要场所，也是学校展示自身文化底蕴和学术实力的重要窗口。");
}

void Widget::on_pushButton5_clicked()
{
    ui->label_text->setText("我是南苑，南京工业大学南苑是南京工业大学的一个校区，位于南京市江宁区龙眠大道30号。南苑校区占地面积约为1500亩，是南京工业大学的主校区之一。这个校区主要包括教学楼、实验楼、图书馆、学生公寓、食堂、体育馆、游泳馆等各种教育和生活设施，为学生提供了良好的学习和生活环境。南京工业大学南苑校区也是南京市高新技术产业园区的一部分，与南京市许多高科技企业和研究机构紧密合作，为学生提供了许多实习和就业机会。");
}

void Widget::on_pushButton6_clicked()
{
    ui->label_text->setText("我是西苑，南京工业大学的西苑是该校的一个重要校区，位于南京市江宁区秣周东路30号，占地面积约为263.6万平方米。西苑校区主要包括学生公寓、教学楼、实验楼、图书馆、体育馆、游泳馆、食堂等综合性建筑，可以满足学生的学习、生活和娱乐需求。西苑校区也是南京工业大学重要的教学、科研和文化活动场所之一，吸引了众多学生和教职员工前来学习和工作。");
}

void Widget::on_pushButton7_clicked()
{
    ui->label_text->setText("我是仁智，南京工业大学仁智楼是南京工业大学的一座教学楼，位于南京市江宁区江宁科学园区，建筑面积约为6.6万平方米。该楼于2014年建成，共有9层，其中包括地下室2层，地上7层。楼内设有多个教室、实验室、教师办公室等，主要用于计算机、通信、控制等专业的教学和科研工作。");
}

void Widget::on_pushButton8_clicked()
{
    ui->label_text->setText("我是镜湖，南京工业大学江浦校区以水为特色，融合了镜湖，君子湖，照心湖，正心湖，益清同济湖等诸多自然景观。镜湖，名字来历无可考，盖晴空万里的日子里站在堤岸上看那一片湖水太过清澈太过明净，犹如明鉴一般倒映着蓝天。镜湖南面有堤，路宽七八米，为建造亚青村重新铺设。沿路右拐就可通往亚青村，路旁柳树成荫看着就有种清凉感。在湖的西南角有一景观休息平台，从堤岸延伸至湖里。镜湖东边有一廊道，名为玉壶廊，沿湖东岸纵穿镜湖南北，廊道两边多种植物交相呼应，如今以是茂密繁盛。湖北面为象山水榭，多么优雅的名字，只愿店如其名便好。水榭往后便是象山食堂和象山苑男生宿舍。");
}

void Widget::on_pushButton9_clicked()
{
    ui->label_text->setText("我是东苑，有学生服务中心，为广大学生的学习生活提供服务");
}

void Widget::on_pushButton10_clicked()
{
    ui->label_text->setText("我是图书馆，南京工业大学图书馆是在原南京化工大学图书馆和原南京建筑工程学院图书馆基础上，于2002年合并而成的。现有江浦校区逸夫图书馆、模范马路校区图书馆、浦江学院图书馆三个分馆，馆内设置办公室、信息系统部、信息咨询部、数字图书馆服务部、文献资源建设部、读者服务部等部门。");
}

void Widget::on_pushButton11_clicked()
{
    ui->label_text->setText("我是亚青，没错就是亚青不夜城（(●'◡'●)）");
}

void Widget::on_pushButton12_clicked()
{
    ui->label_text->setText("我是学府苑，老师们住的地方");
}

//获取最短路径
void Widget::on_pushButton_short_clicked()

{
    QString msg1;
    //获取起点和终点
    qi=ui->lineEdit_qi->text();
    zhong=ui->lineEdit_zhong->text();
    //利用dijkstra返回要打印的最短路径信息
    msg1=dijkstra(g, qi.toUInt(), zhong.toUInt());
    ui->label_text->setText(msg1);
}


//获取所有路径
void Widget::on_pushButton_all_clicked()
{
    QString msg1;
    //获取起点和终点
    qi=ui->lineEdit_qi->text();
    zhong=ui->lineEdit_zhong->text();
    //利用allroads函数返回所有路径信息
    msg1=allroads(g, qi.toUInt(), zhong.toUInt());
    ui->label_text->setText(msg1);
}

//对路径长度进行更新
void Widget::on_pushButton_updatelj_clicked()
{
    QString msg1;
    //获取起点和终点,路径
    qi=ui->lineEdit_qi->text();
    zhong=ui->lineEdit_zhong->text();
    lujing=ui->lineEdit_lujing->text();
    //利用gengxin函数对路径更新
    msg1=gengxin(g,qi.toUInt(),zhong.toUInt(),lujing.toUInt());
    ui->label_text->setText(msg1);
}

//删除路径
void Widget::on_pushButton_deletelj_clicked()
{
    QString msg1;
    //获取起点和终点
    qi=ui->lineEdit_qi->text();
    zhong=ui->lineEdit_zhong->text();
    lujing=ui->lineEdit_lujing->text();
    //利用gengxin函数对路径更新
    msg1=deleteroad(g,qi.toUInt(),zhong.toUInt(),lujing.toUInt());
    ui->label_text->setText(msg1);
}

//添加景点
void Widget::on_pushButton_addjd_clicked()
{
    QString msg1;
    //获取新增节点（qi）
    qi=ui->lineEdit_qi->text();
    msg1=addv(g);
    ui->label_text->setText(msg1);
}

//删除景点
void Widget::on_pushButton_deletejd_clicked()
{
    QString msg1;
    //获取要删除节点(zhong)
    zhong=ui->lineEdit_zhong->text();
    //利用gengxin函数对路径更新
    msg1=deletev(g,zhong.toUInt());
    ui->label_text->setText(msg1);
}

//添加路径
void Widget::on_pushButton_addlj_clicked()
{
    QString msg1;
    //获取起点终点和路径长
    qi=ui->lineEdit_qi->text();
    zhong=ui->lineEdit_zhong->text();
    lujing=ui->lineEdit_lujing->text();
    //利用gengxin函数对路径更新
    add_edge(g,qi.toUInt(),zhong.toUInt(),lujing.toUInt());
    msg1="已成功添加路径"+qi+"——"+zhong+",其路径长为:"+lujing;
    ui->label_text->setText(msg1);
}
