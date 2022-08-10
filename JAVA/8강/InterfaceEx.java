public class InterfaceEx {
    public interface TV{
		public int MIN_VOL = 0;
		public int MAX_VOL = 100;
		public void turnOn(); //추상메소드와 비슷하게 선언
		public void turnOff();
		public void chagneVolume(int volume);
		public void chagneChannel(int channel);
}
public class LedTV implements TV{
		public void turnOn(){
		System.out.println("전원ON");
}
		public void turnOff(){
		System.out.println("전원OFF");
}
		public void chagneVolume(int volume){
		System.out.println("볼륨 조절");
}
		public void chagneChannel(int channel){
		System.out.println("채널 변경");
}
}

public static void main(String [] args){
	Tv tv = new LedTV();
	tv.turnOn();
	tv.turnOff();
	tv.turnchangeVolume(10);
	tv.turnchangeChannel(20);
}
}
