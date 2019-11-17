import staticProxy.StaticProxy;
import staticProxy.Hello;
import staticProxy.IHello;

public class Proxy {
	public static void main(String[] args) {
		Hello hello = new Hello();
		StaticProxy staticProxy = new StaticProxy();
		staticProxy.setIHello(hello);
		staticProxy.sayHello();
	}
}
