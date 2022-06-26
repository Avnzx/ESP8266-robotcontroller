function clamp (number,min,max) {
    return Math.min(Math.max(number, min), max);
}

function applyDeadband(axisin, deadband = 0.1) {
    if (Math.abs(axisin) > deadband) {
        if (axisin > 0.0) {
          return (axisin - deadband) / (1.0 - deadband);
        } else {
          return (axisin + deadband) / (1.0 - deadband);
        }
      } else {
        return 0.0;
      }
}


function squareInput(input){
  return (Math.sign(input) * (input*input));
}


function curvatureDriveIK(xSpd,zRot,allowTurnInPlace = false) {
  xSpd = squareInput(xSpd); // "square" the inputs and multip by std::copysign
  zRot = squareInput(zRot);

  var xSpeed = clamp(xSpd, -1.0, 1.0);
  var zRotation = clamp(zRot, -1.0, 1.0);

  var leftSpeed = 0.0;
  var rightSpeed = 0.0;

  if (allowTurnInPlace) {
    leftSpeed = xSpeed + zRotation;
    rightSpeed = xSpeed - zRotation;
  } else {
    leftSpeed = xSpeed + Math.abs(xSpeed) * zRotation;
    rightSpeed = xSpeed - Math.abs(xSpeed) * zRotation;
  }

  // Normalize wheel speeds
  var maxMagnitude = Math.max(Math.abs(leftSpeed), Math.abs(rightSpeed));
  if (maxMagnitude > 1.0) {
    leftSpeed /= maxMagnitude;
    rightSpeed /= maxMagnitude;
  }

  return [leftSpeed, rightSpeed];
}