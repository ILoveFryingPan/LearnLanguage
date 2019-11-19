package dynamic;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;

public class HelloInvocationHandler<T> implements InvocationHandler {
	T target;
	public HelloInvocationHandler(T target)  {
		this.target = target;
	}

	@Override
	public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
		System.out.println("这里是动态的代理：开始");
		Object result = method.invoke(target, args);
		System.out.println("这里是动态的代理：结束");
		return result;
	}
}	
