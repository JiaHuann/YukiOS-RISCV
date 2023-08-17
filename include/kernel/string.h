/*
 * @Author: JiaHuann cheayuki13@gmail.com
 * @Date: 2023-08-17 14:50:02
 * @LastEditors: JiaHuann cheayuki13@gmail.com
 * @LastEditTime: 2023-08-17 14:54:32
 * @FilePath: \oskernel2023-xupt-orz\include\kernel\string.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
void *memset(void *dest, int c, size_t n)
{
    char *p = dest;
    for (int i = 0; i < n; ++i, *(p++) = c)
        ;
    return dest;
}