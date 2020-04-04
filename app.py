from stuclass import student
from banji import banji
wangluo = banji()

def menu():
    print("1、添加学生信息")
    print("2、删除学生信息")
    print("3、查询学生信息")
    print("4、修改学生信息")
    print("5、遍历学生信息")
    print("6、退出系统")
def main():
    while True:
        menu()
        key = input("请输入你选择的序号：")
        if key == "1":
            wangluo.addstufrominput()
        elif key == "2":
            wangluo.delstu()
        elif key == "3":
            wangluo.printstu()
        elif key == "4":
            wangluo.changestu()
        elif key == "5":
            wangluo.allstu()
main()

