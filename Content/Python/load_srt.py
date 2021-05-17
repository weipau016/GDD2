
import pathlib
import unreal

class Sequence :
    def __init__(self, index, start, duration, text):
        self.start = start
        self.index = index
        self.duration = duration
        self.text = text

path_to_project = 'C:/Users/renowsky/Documents/TU/GDD2/WrongDirection/GDD2'

def read_srt() :

    read_index = True
    read_time_stamp = False
    read_text = False
    sequences = []
    
    with open(path_to_project + '/Content/Story/welcome-al/welcome-al-1.srt') as fp:
        
        # read all lines
        lines = fp.readlines()
        
        # initialize variables
        current_index = -1
        current_start = 0.0
        current_duration = 0.0
        text = ""
        
        # parse lines
        for line in lines:
        
            # read text part
            if read_text :
                # check if we are done
                if line == "\n":
                    read_index = True
                    read_text = False
                    sequences.append(Sequence(current_index, current_start, current_duration, text))
                    text = ''
                    continue
                
                # append line to text
                text += line
            
            # read the sequence index
            if read_index == True:
                current_index = int(line.split()[0])
                read_index = False
                read_time_stamp = True
                continue
            
            # read the time stamp
            if read_time_stamp:
                split = line.split(' ')
                start = split[0]
                end = split[2]
                
                start = start.split(':')
                start[2] = start[2].replace(',', '.')
                end = end.split(':')
                end[2] = end[2].replace(',', '.')
                
                unreal.log(start[2])
                
                # convert start to seconds
                start = float(start[0]) * 60 * 60 + float(start[1]) * 60 + float(start[2])
                current_start = start
                
                # convert end to seconds
                end = float(end[0]) * 60 * 60 + float(end[1]) * 60 + float(end[2])
                current_duration = end - start
                
                read_time_stamp = False
                read_text = True
                continue
                
            #unreal.log(line)
    return sequences
    
    
sequences = read_srt()
for sequence in sequences:
    unreal.log("Sequence")
    unreal.log(sequence.index)
    unreal.log(sequence.start)
    unreal.log(sequence.duration)
    unreal.log(sequence.text)
    
actors = unreal.EditorLevelLibrary.get_all_level_actors()

# get the generated class of the Blueprint (note the _C)
bp_gc = unreal.load_object(None, "/Game/Story/StoryConfig.StoryConfig_C")
# get the Class Default Object (CDO) of the generated class
bp_cdo = unreal.get_default_object(bp_gc)
# set the default property values
scenes = bp_cdo.get_editor_property("scenes")

# clear scenes dictionary






