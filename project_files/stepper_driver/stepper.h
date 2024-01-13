
#ifndef STEPPER_H
#define STEPPER_H

#define FULL_CIRCLE_STEPS (200) /**< Number of steps for a full rotation. */

/** Module return values. */
typedef enum
{
	STEPPER_RETURN_OK = 0,	/**< Success. */
	STEPPER_RETURN_ERROR,	/**< Generic error. */
} stepper_return;

/**
 * Rotate motor 360°.
 */
extern stepper_return stepper_make_full_rotation (void);

/**
 * Rotate given number of degrees.
 *
 * @param degrees Number of degrees to turn.
 */
extern stepper_return stepper_rotate_degrees (int degrees);


#endif /* STEPPER_H */

