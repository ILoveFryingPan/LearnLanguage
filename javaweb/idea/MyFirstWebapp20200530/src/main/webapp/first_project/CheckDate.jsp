<%@ page language="java" pageEncoding="utf-8" %>
<!DOCTYPE html>
<html>
    <head>
        <title>验证输入的日期格式是否正确</title>
        <script language="javascript">
            //判断输入的日期是否正确
            function checkDate(inDate) {
                if("" == inDate) {
                    return true;
                }
                if(inDate.indexOf('-', 0) != -1) {
                    separate = "-"
                } else {
                    if(inDate.indexOf('/', 0) != -1) {
                        separate = "/"
                    } else {
                        return true;
                    }
                }

                area = inDate.indexOf(separate, 0)
                //获取年份
                subYY = inDate.substr(0, area)
                if(isNaN(subYY) || 0 >= subYY) {
                    return true;
                }
                //转换月份
                subMM = inDate.substr(area + 1, inDate.indexOf(separate, area + 1) - (area + 1))
                if(isNaN(subMM) || 0 >= subMM) {
                    return true;
                }

                if(subMM.length < 2) {
                    subMM = "0" + subMM
                }
                //转换日
                area = inDate.lastIndexOf(separate)
                subDD = inDate.substr(area + 1, inDate.length - area - 1)
                if(isNaN(subDD) || 0 >= subDD) {
                    return true;
                }
                if(10 > eval(subDD)) {
                    subDD = "0" + eval(subDD)
                }
                newDate = subYY + "-" + subMM + "-" + subDD
                if(10 != newDate.length) {
                    return true;
                }
                if("-" != newDate.substr(4, 1)) {
                    return true;
                }
                if("-" != newDate.substr(7, 1)) {
                    return true;
                }
                var MM = newDate.substr(5, 2);
                var DD = newDate.substr(8, 2);
                if((0 == subYY % 4 && 0 != subYY % 100) || 0 == subYY % 400) {
                    //判断是否为闰年
                    if(2 == parseInt(MM)) {
                        if(29 < DD) {
                            return true;
                        }
                    }
                } else {
                    if(2 == parseInt(DD)) {
                        if(28 < DD) {
                            return true;
                        }
                    }
                }
                var mm = new Array(1, 3, 5, 7, 8, 10, 12);
                //判断每月中的最大天数
                for(i = 0; i < mm.length; i++) {
                    if(parseInt(MM) == mm[i]) {
                        if(31 < parseInt(DD)) {
                            return true;
                        } else {
                            return false;
                        }
                    }
                }
                if(30 < parseInt(DD)) {
                    return true;
                }
                if(12 < parseInt(MM)) {
                    return true;
                }
                return false;
            }
        </script>
        <script language="javascript">
            function check(myform) {
                if("" == myform.sDate.value) {
                    alert("请输入日期");
                    myform.sDate.focus();
                    return;
                }
                if(checkDate(myform.sDate.value)) {
                    alert("您输入的日期不正确！\n请注意日期格式（如：2007/07/17或2007-07-17）以及二月是否为闰年！");
                    myform.sDate.focus();
                    return;
                }
                if(!checkDate(myform.sDate.value)) {
                    alert("您输入的日期是正确的！");
                }
                myform.submit();
            }
        </script>
    </head>
    <body>
        <form action="" method="post" name="form1">
        <table width="98%" height="38" border="0" cellpadding="0" cellspacing="0">
            <input name="sDate" type="text" id="sDate">
            <input name="Button" type="button" value="检测日期" onClick="check(form1)">
        </table>
        </form>
    </body>
</html>