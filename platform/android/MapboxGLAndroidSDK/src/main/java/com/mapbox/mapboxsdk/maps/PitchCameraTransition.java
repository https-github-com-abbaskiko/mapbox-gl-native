package com.mapbox.mapboxsdk.maps;

import android.view.animation.Interpolator;

public class PitchCameraTransition extends CameraTransition<Double> {

  public PitchCameraTransition(int type, long duration, long delay, Double endValue, Interpolator interpolator) {
    super(type, duration, delay, endValue, interpolator);
  }

  @Override
  int getCameraProperty() {
    return PROPERTY_PITCH;
  }

  @Override
  protected Double getAnimatedValue(double fraction) {
    return getStartValue() + ((getEndValue() - getStartValue()) * fraction);
  }

  public static class Builder extends CameraTransition.Builder<PitchCameraTransition, Double> {

    public Builder(Double endValue) {
      super(endValue);
    }

    @Override
    public PitchCameraTransition build() {
      return new PitchCameraTransition(reason, durationMillis, delayMillis, endValue, interpolator);
    }
  }
}
