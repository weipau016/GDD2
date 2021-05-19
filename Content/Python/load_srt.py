
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
    
def add_srt_sequences(sequences, new_sequence, prototype_srt_sequence):
    # initialize srt sequences
    for sequence in sequences:
    
        # copy prototype
        new_srt_sequence = prototype_srt_sequence.copy()
        
        # set parsed values
        new_srt_sequence.start_time = sequence.start
        new_srt_sequence.duration = sequence.duration
        new_srt_sequence.text = sequence.text
        
        # append srt sequence to current scene sequence
        new_sequence.srt_sequences.append(new_srt_sequence)

sequences = read_srt()
for sequence in sequences:
    unreal.log("Sequence")
    unreal.log(sequence.index)
    unreal.log(sequence.start)
    unreal.log(sequence.duration)
    unreal.log(sequence.text)

# get the generated class of the Blueprint (note the _C)
bp_gc = unreal.load_object(None, "/Game/Story/StoryConfig.StoryConfig_C")

# get the Class Default Object (CDO) of the generated class
bp_cdo = unreal.get_default_object(bp_gc)

# get scene config dictionary from CDO
scene_config = bp_cdo.get_editor_property("scene_config")

# clear scene config
scene_config.clear()

# get dummy structs to clone from
prototype_sequence = bp_cdo.get_editor_property("dummy_sequence")
prototype_srt_sequence = bp_cdo.get_editor_property("dummy_srt_sequence")

# get scene sequences array
scene_sequences = bp_cdo.get_editor_property("sequences")

# clear scene sequences array
scene_sequences = []

# clone prototypes
new_sequence = prototype_sequence.copy()

# load the sound asset -TODO import these
sound_asset = unreal.EditorAssetLibrary.load_asset('/Game/Story/welcome-al/welcome-al-1.welcome-al-1')

# set audio track
new_sequence.sound_track = sound_asset

# add srt sequences
add_srt_sequences(sequences, new_sequence, prototype_srt_sequence)

scene_sequences.append(new_sequence)

# set scene sequences in editor
bp_cdo.set_editor_property("sequences", scene_sequences)


unreal.log(scene_sequences)

# clear scenes dictionary





