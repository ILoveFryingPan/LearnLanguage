<%@ page language="java" contentType="text/html; charset=utf-8" pageEncoding="utf-8" %>
<%@ page import="java.util.Date" %>
<%@ page import="java.util.Map" %>
<!doctype html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
        <title>Insert title here</title>
    </head>
    <body>
        <%
            String str = "";
            //声明保存九九乘法表的字符串变量
            //连接生成九九乘法表的字符串
            for(int i = 1; i <= 9; i++) {
                //外循环
                for(int j = 1; j <= i; j++) {
                    //内循环
                    str += j + "*" + i + "=" + j * i;
                    str += "&nbsp;";    //加入空格符
                }
                str += "<br>";          //加入换行符
            }
        %>
        <!--<%= new Date()%>-->
        <table width="440" height="85" border="1" cellpadding="0" cellspacing="0" style="font:9pt;" bordercolordark="#666666" bordercolorlight="#ffffff" bordercolor="#ffffff">
            <tr>
                <td height="30" align="center">九九乘法表 <%--表格的标题--%></td>
            </tr>
            <tr>
                <td style="padding:3pt">
                    <%= str %>
                </td>
            </tr>
            <tr>
                <td>
                    <jsp:include page="index.jsp"/>
                </td>
            </tr>
        </table>
    </body>
</html>