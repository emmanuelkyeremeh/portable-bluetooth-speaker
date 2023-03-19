clear All;
global bt;
instrhwinfo('Bluetooth','HC-05');
bt = Bluetooth('HC-05',1);
fopen(bt);

function pushbutton2_Callback(hObject, eventdata, handles)

global bt;
file = uigetfile('*');

if strcmp(file,'sample1.wav') == 1
    fprintf(bt,'1');
elseif strcmp(file,'sample2.wav') == 1
    fprintf(bt,'2');
elseif strcmp(file,'sample3.wav') == 1  
    fprintf(bt,'3');  
else
    fprintf(bt,'4');
end

function pushbutton1_Callback(hObject, eventdata, handles)

global bt;
fprintf(bt,'P');


function pushbutton3_Callback(hObject, eventdata, handles)

global bt;
fprintf(bt,'S');
