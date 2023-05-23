/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.7 */

#ifndef PB_SCIENCE_PB_H_INCLUDED
#define PB_SCIENCE_PB_H_INCLUDED
#include "utils/pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _PumpState {
    PumpState_PUMP_STATE_UNDEFINED = 0,
    PumpState_PUMP_ON = 1,
    PumpState_PUMP_OFF = 2
} PumpState;

typedef enum _DirtReleaseState {
    DirtReleaseState_DIRT_RELEASE_STATE_UNDEFINED = 0,
    DirtReleaseState_OPEN_DIRT = 1,
    DirtReleaseState_CLOSE_DIRT = 2
} DirtReleaseState;

typedef enum _ScienceState {
    ScienceState_SCIENCE_STATE_UNDEFINED = 0,
    ScienceState_COLLECT_DATA = 1,
    ScienceState_STOP_COLLECTING = 2
} ScienceState;

/* Struct definitions */
typedef struct _ScienceCommand {
    /* Individual control over each motor. Indicates steps to move */
    float dirt_carousel;
    float dirt_linear;
    float science_linear;
    float vacuum_linear;
    /* Vacuum */
    PumpState vacuum; /* percentage, from 0-1 */
    DirtReleaseState dirtRelease;
    /* Pumps */
    PumpState pump1;
    PumpState pump2;
    PumpState pump3;
    PumpState pump4;
    /* High level commands */
    bool calibrate;
    bool stop;
    bool next_tube;
    bool next_section;
    int32_t sample;
    ScienceState state;
} ScienceCommand;

typedef struct _ScienceData {
    float co2;
    float humidity;
    float methane;
    float pH;
    float temperature;
    int32_t sample;
    ScienceState state;
} ScienceData;


#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _PumpState_MIN PumpState_PUMP_STATE_UNDEFINED
#define _PumpState_MAX PumpState_PUMP_OFF
#define _PumpState_ARRAYSIZE ((PumpState)(PumpState_PUMP_OFF+1))

#define _DirtReleaseState_MIN DirtReleaseState_DIRT_RELEASE_STATE_UNDEFINED
#define _DirtReleaseState_MAX DirtReleaseState_CLOSE_DIRT
#define _DirtReleaseState_ARRAYSIZE ((DirtReleaseState)(DirtReleaseState_CLOSE_DIRT+1))

#define _ScienceState_MIN ScienceState_SCIENCE_STATE_UNDEFINED
#define _ScienceState_MAX ScienceState_STOP_COLLECTING
#define _ScienceState_ARRAYSIZE ((ScienceState)(ScienceState_STOP_COLLECTING+1))

#define ScienceCommand_vacuum_ENUMTYPE PumpState
#define ScienceCommand_dirtRelease_ENUMTYPE DirtReleaseState
#define ScienceCommand_pump1_ENUMTYPE PumpState
#define ScienceCommand_pump2_ENUMTYPE PumpState
#define ScienceCommand_pump3_ENUMTYPE PumpState
#define ScienceCommand_pump4_ENUMTYPE PumpState
#define ScienceCommand_state_ENUMTYPE ScienceState

#define ScienceData_state_ENUMTYPE ScienceState


/* Initializer values for message structs */
#define ScienceCommand_init_default              {0, 0, 0, 0, _PumpState_MIN, _DirtReleaseState_MIN, _PumpState_MIN, _PumpState_MIN, _PumpState_MIN, _PumpState_MIN, 0, 0, 0, 0, 0, _ScienceState_MIN}
#define ScienceData_init_default                 {0, 0, 0, 0, 0, 0, _ScienceState_MIN}
#define ScienceCommand_init_zero                 {0, 0, 0, 0, _PumpState_MIN, _DirtReleaseState_MIN, _PumpState_MIN, _PumpState_MIN, _PumpState_MIN, _PumpState_MIN, 0, 0, 0, 0, 0, _ScienceState_MIN}
#define ScienceData_init_zero                    {0, 0, 0, 0, 0, 0, _ScienceState_MIN}

/* Field tags (for use in manual encoding/decoding) */
#define ScienceCommand_dirt_carousel_tag         1
#define ScienceCommand_dirt_linear_tag           2
#define ScienceCommand_science_linear_tag        3
#define ScienceCommand_vacuum_linear_tag         4
#define ScienceCommand_vacuum_tag                5
#define ScienceCommand_dirtRelease_tag           7
#define ScienceCommand_pump1_tag                 8
#define ScienceCommand_pump2_tag                 9
#define ScienceCommand_pump3_tag                 10
#define ScienceCommand_pump4_tag                 11
#define ScienceCommand_calibrate_tag             12
#define ScienceCommand_stop_tag                  13
#define ScienceCommand_next_tube_tag             14
#define ScienceCommand_next_section_tag          15
#define ScienceCommand_sample_tag                16
#define ScienceCommand_state_tag                 17
#define ScienceData_co2_tag                      1
#define ScienceData_humidity_tag                 2
#define ScienceData_methane_tag                  3
#define ScienceData_pH_tag                       4
#define ScienceData_temperature_tag              5
#define ScienceData_sample_tag                   6
#define ScienceData_state_tag                    7

/* Struct field encoding specification for nanopb */
#define ScienceCommand_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, FLOAT,    dirt_carousel,     1) \
X(a, STATIC,   SINGULAR, FLOAT,    dirt_linear,       2) \
X(a, STATIC,   SINGULAR, FLOAT,    science_linear,    3) \
X(a, STATIC,   SINGULAR, FLOAT,    vacuum_linear,     4) \
X(a, STATIC,   SINGULAR, UENUM,    vacuum,            5) \
X(a, STATIC,   SINGULAR, UENUM,    dirtRelease,       7) \
X(a, STATIC,   SINGULAR, UENUM,    pump1,             8) \
X(a, STATIC,   SINGULAR, UENUM,    pump2,             9) \
X(a, STATIC,   SINGULAR, UENUM,    pump3,            10) \
X(a, STATIC,   SINGULAR, UENUM,    pump4,            11) \
X(a, STATIC,   SINGULAR, BOOL,     calibrate,        12) \
X(a, STATIC,   SINGULAR, BOOL,     stop,             13) \
X(a, STATIC,   SINGULAR, BOOL,     next_tube,        14) \
X(a, STATIC,   SINGULAR, BOOL,     next_section,     15) \
X(a, STATIC,   SINGULAR, INT32,    sample,           16) \
X(a, STATIC,   SINGULAR, UENUM,    state,            17)
#define ScienceCommand_CALLBACK NULL
#define ScienceCommand_DEFAULT NULL

#define ScienceData_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, FLOAT,    co2,               1) \
X(a, STATIC,   SINGULAR, FLOAT,    humidity,          2) \
X(a, STATIC,   SINGULAR, FLOAT,    methane,           3) \
X(a, STATIC,   SINGULAR, FLOAT,    pH,                4) \
X(a, STATIC,   SINGULAR, FLOAT,    temperature,       5) \
X(a, STATIC,   SINGULAR, INT32,    sample,            6) \
X(a, STATIC,   SINGULAR, UENUM,    state,             7)
#define ScienceData_CALLBACK NULL
#define ScienceData_DEFAULT NULL

extern const pb_msgdesc_t ScienceCommand_msg;
extern const pb_msgdesc_t ScienceData_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define ScienceCommand_fields &ScienceCommand_msg
#define ScienceData_fields &ScienceData_msg

/* Maximum encoded size of messages (where known) */
#define ScienceCommand_size                      55
#define ScienceData_size                         38

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
