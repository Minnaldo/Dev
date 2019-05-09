import os


cur_path = os.getcwd()

path_dir = cur_path+'/test'

file_list = os.listdir(path_dir)
file_list.sort()

for item in file_list:
    if item.find('some_string') is not -1:
        print item