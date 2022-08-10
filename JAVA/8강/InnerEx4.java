public class InnerEx4 {
    //추상클래스 Action 
    public abstract class Action{
        public abstract void exec();
    }

    //추상클래스 Action을 상속받은 클래스 MyAction

    public class MyAction extends Action{
        public void exec(){
            System.out.println("exec");
        }
    }

// 원래 추상클래스를 구현하던 방식

    //MyAction을 사용하는 클래스 ActionExam 
    public class ActionExam{
        public static void main(String args[]){
            Action action = new MyAction(); //추상 클래스는 객체화 할 수 없으므로
            action.exec();
        }
    }

//////////////  익명 클래스 사용 ////////////////

    //MyAction을 사용하지 않고 Action을 상속받는 익명 클래스를 만들어서 사용하도록 수정
    public class ActionExam{
        public static void main(String args[]){
            Action action = new Action(){ //추상 클래스를 객체화 함과 동시에 익명클래스 사용
                public void exec(){
                    System.out.println("exec");
                }
            };
            action.exec();
        }
    }

//////////////  익명 클래스 사용 ////////////////
}
