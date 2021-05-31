import pathlib
import unreal
from os import listdir
from os.path import isfile, join, isdir
import os

path_to_project = __file__[0: len(__file__) - len('Content/Python/load_srt.py')]

class Sequence :
    def __init__(self, index, start, duration, text):
        self.start = start
        self.index = index
        self.duration = duration
        self.text = text

def read_srt(path) :

    read_index = True
    read_time_stamp = False
    read_text = False
    sequences = []
    
    with open(path_to_project + '/Content/Story/' + path) as fp:
        
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
                    sequences.append(Sequence(current_index, current_start + 0.1, current_duration, text))
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
        
def import_sound_assets(destination_folder):
    dir = path_to_project + '/Content/Story/' + destination_folder
    files = [f for f in listdir(dir) if isfile(join(dir, f)) and f[-3:]=='ogg']
    AssetTools = unreal.AssetToolsHelpers.get_asset_tools()

    import_tasks = []
    for f in files:
        print (join(dir, f))
        AssetImportTask = unreal.AssetImportTask()
        AssetImportTask.set_editor_property('filename', join(dir, f))
        AssetImportTask.set_editor_property('destination_path', '/Game/Story/' + destination_folder)
        AssetImportTask.set_editor_property('save', True)
        AssetImportTask.set_editor_property('replace_existing', True)
        AssetImportTask.set_editor_property('automated', True)
        import_tasks.append(AssetImportTask)

    AssetTools.import_asset_tasks(import_tasks)

# get story directory path
story_directory = path_to_project + '/Content/Story/'

# get directory contents
directory_contents = listdir(story_directory)

# import all audio files
for item in directory_contents:
    if isdir(join(story_directory, item)):
        # import sound assets
        pass
        #import_sound_assets(item + '/')


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

# clear scene sequences
scene_sequences = []

for item in directory_contents:
    if isdir(join(story_directory, item)):
    
        # get current scene directory
        current_scene = join(story_directory, item)
        
        # get all srt files
        srt_files = [f for f in listdir(current_scene) if isfile(join(current_scene, f)) and f[-3:]=='srt']
        unreal.log(srt_files)
        
        scene_config.setdefault(item, len(scene_sequences))
        
        # parse srt files for current scene
        for srt_file in srt_files:
        
            new_sequence = prototype_sequence.copy()
        
            # read srt file
            sequences = read_srt(item + '/' + srt_file)
            
            sound_name = srt_file.split('.')[0]
            unreal.log(sound_name)
            
            # load the sound asset
            sound_asset = unreal.EditorAssetLibrary.load_asset('/Game/Story/' + item + '/' + sound_name + '.' + sound_name)
            
            # set audio track
            new_sequence.sound_track = sound_asset
            
            # add srt sequences
            add_srt_sequences(sequences, new_sequence, prototype_srt_sequence)
            '''
            for sequence in sequences:
                unreal.log("Sequence")
                unreal.log(sequence.index)
                unreal.log(sequence.start)
                unreal.log(sequence.duration)
                unreal.log(sequence.text)
            '''
            scene_sequences.append(new_sequence)





# set scene sequences in editor
bp_cdo.set_editor_property("sequences", scene_sequences)


#unreal.log(scene_sequences)

# clear scenes dictionary





