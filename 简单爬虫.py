# coding=utf-8
import requests
import re
import json
 
class Neihan:
    def __init__(self):
        self.start_url = "http://neihanshequ.com/"
        self.headers = {"User-Agent":"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.100 Safari/537.36"}
        self.next_url_temp = "http://neihanshequ.com/joke/?is_json=1&app_name=neihanshequ_web&max_time={}"
 
    def parse_url(self,url): #����url��ַ�����󣬻�ȡ��Ӧ
        r = requests.get(url,headers=self.headers)
        return r.content.decode()
 
    def get_first_page_content_list(self,html_str):
        t = re.findall(r"<h1 class=\"title\">.*?<p>(.*?)</p>.*?</h1>", html_str, re.S)
        #��ȡmax����time
        max_time = re.findall("max_time: '(.*?)'",html_str,re.S)[0]
        return t,max_time
 
    def save_content_list(self,content_list): #����
        for content in content_list:
            print(content)
 
    def get_content_list(self,html_str):
        dict_response = json.loads(html_str)
        content_list = [i["group"]['text']  for i in dict_response["data"]["data"]]
        max_time = dict_response["data"]["max_time"]
        #��ȡhas_more
        has_more = dict_response["data"]["has_more"]
        return content_list,max_time,has_more
 
    def run(self):#ʵ����Ҫ�߼�
        #1.start_url
        #2.�������󣬻�ȡ��Ӧ
        html_str = self.parse_url(self.start_url)
        #3.��ȡ����
        content_list,max_time = self.get_first_page_content_list(html_str)
        #4.����
        self.save_content_list(content_list)
        #5.��ȡ�ڶ�ҳ��url
        has_more=True
        while has_more:
            next_url = self.next_url_temp.format(max_time)
            html_str = self.parse_url(next_url)  #������һҳ������
            content_list,max_time,has_more = self.get_content_list(html_str)#��ȡjson�еĶ��Ӻ�max����time
            self.save_content_list(content_list)
 
if __name__ == '__main__':
    neihan = Neihan()
    neihan.run()