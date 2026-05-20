/**
 * @file lv_ffmpeg.h
 *
 */
#ifndef LV_FFMPEG_H
#define LV_FFMPEG_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../../lv_conf_internal.h"
#if LV_USE_FFMPEG != 0
#include "../../misc/lv_types.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
struct ffmpeg_context_s;

LV_ATTRIBUTE_EXTERN_DATA extern const lv_obj_class_t lv_ffmpeg_player_class;

typedef enum {
    LV_FFMPEG_PLAYER_CMD_START,
    LV_FFMPEG_PLAYER_CMD_STOP,
    LV_FFMPEG_PLAYER_CMD_PAUSE,
    LV_FFMPEG_PLAYER_CMD_RESUME,
    LV_FFMPEG_PLAYER_CMD_LAST
} lv_ffmpeg_player_cmd_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Register FFMPEG image decoder
 */
void lv_ffmpeg_init(void);

/**
 * Get the number of frames contained in the file
 * @param path image or video file name
 * @return Number of frames, less than 0 means failed
 */
int lv_ffmpeg_get_frame_num(const char * path);

/**
 * Create ffmpeg_player object
 * @param parent pointer to an object, it will be the parent of the new player
 * @return pointer to the created ffmpeg_player
 */
lv_obj_t * lv_ffmpeg_player_create(lv_obj_t * parent);

/**
 * Set the path of the file to be played
 * @param obj pointer to a ffmpeg_player object
 * @param path video file path
 * @return LV_RESULT_OK: no error; LV_RESULT_INVALID: can't get the info.
 */
lv_result_t lv_ffmpeg_player_set_src(lv_obj_t * obj, const char * path);

/**
 * Set command control video player
 * @param obj pointer to a ffmpeg_player object
 * @param cmd control commands
 */
void lv_ffmpeg_player_set_cmd(lv_obj_t * obj, lv_ffmpeg_player_cmd_t cmd);

/**
 * Set the video to automatically replay
 * @param obj pointer to a ffmpeg_player object
 * @param en true: enable the auto restart
 */
void lv_ffmpeg_player_set_auto_restart(lv_obj_t * obj, bool en);

void lv_ffmpeg_player_set_playdone_event(lv_obj_t * obj, void (*event_cb)(lv_obj_t * obj, void * user_data),
                                         void * user_data);

void lv_ffmpeg_player_update_frame(lv_obj_t * obj);

void lv_ffmpeg_player_seek(lv_obj_t * obj, int64_t timestamp_ms);
int64_t lv_ffmpeg_player_get_pts(lv_obj_t * obj);
int64_t lv_ffmpeg_player_get_duration(lv_obj_t * obj);
void lv_ffmpeg_player_pause(lv_obj_t * obj);
void lv_ffmpeg_player_resume(lv_obj_t * obj);

/*=====================
 * Other functions
 *====================*/

/**********************
 *      MACROS
 **********************/

#endif /*LV_USE_FFMPEG*/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_FFMPEG_H*/
